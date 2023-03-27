<?php

require_once('vendor/autoload.php');
use Scriptotek\Alma\Client as AlmaClient;
use Scriptotek\Alma\Sru\Client as SruClient;

#-----------------------------------------------------------
# Functions
#-----------------------------------------------------------

/*
 * searchForId - Not used - kept for later if needed.
 */
function searchForId($id, $array) {
    foreach ($array as $key => $val) {
       if ($val['ID'] === $id) {
           return $key;
       }
    }
    return null;
}

/*
 * searchForCode
 *
 * inputs:
 *  $code   - The code we are looking for in the $array.
 *  $array  - The array we are looking in for the $code.
 *
 * output:
 *  $key    - The key to the array for the found code.
 *  null    - If the key is not found.
 */
function searchForCode($code, $array) {
    foreach ($array as $key => $val) {
        if ($val['code'] === $code) {
            return $key;
        }
    }
    return null;
}

/*
 * searchForName - Return the Key of the found Job Name
 *
 * inputs:
 *  $name   - The name of the job we are looking for in the array.
 *  $array  - The array we are looking in for the name.
 *
 * output:
 *  $key    - The key to the array for the found name.
 *  null    - If the key was not found.
 */
function searchForName($name, $array) {
    foreach ($array as $key => $val) {
       if ($val['NAME'] === $name) {
           return $key;
       }
    }
    return null;
}

/*
 * after - Return the portion string that follows in a given string.
 *
 * inputs:
 *      $this_in - What string we are looking for (needle).
 *      $inthat  - What string we are looking into (haystack).
 *
 * output:
 *      the string after the $this_in variable.
 */
function after ($this_in, $inthat) {
    if (!is_bool(strpos($inthat, $this_in)))
    return substr($inthat, strpos($inthat,$this_in)+strlen($this_in));
};

/*
 * instanceStatus - Get's the status of the instance.
 *
 * inputs:
 *      $apikey = The API key used to connect to Alma.
 *      $job_id = The Job ID that the job was submitted under.
 *      $instance_id = The Instance ID that the submitted job returned.
 *
 * output:
 *      status - As defined in the code portion of the codeTable 'systemJobStatus'
 *      null   - If unable to pull the status.
 */
function instanceStatus($apikey,$domain,$job_id, $instance_id)
{
    $j_alma = new AlmaClient($apikey,$domain);
    $j_job = $j_alma->jobs[$job_id];
    $j_instances = $j_job->instances;
    $j_instance_info = $j_instances[$instance_id];
    if ($j_instance_info)
    {
        $j_status = $j_instance_info->status->value;
        return($j_status);
    } else {
        return(null);
    }
}

/*
 * zuluToLocal - Convert Zulu Time to Local Time.
 *
 * input:
 *      datetimestamp in Zulu Time zone.
 *
 * output:
 *      datetimestamp in Local Time zone.
 *
 * Note: occationally this function fails due to a microtime issue:
 *   https://stackoverflow.com/questions/53738427/php-error-call-to-a-member-function-settimezone-on-boolean
 *
 */
function zuluToLocal($in)
{
    # Zulu is UTC so create timezone.
    $tz = new DateTimeZone("UTC");
    # Create Date/Time from the format given to UTC.
    $date = DateTime::createFromFormat('Y-m-d\TH:i:s.v\Z', $in, $tz);
    #print_r($date);
    # Convert the timezone to 'America/New_York';
    $date->setTimezone(new DateTimeZone('America/New_York'));
    # Return the Date/Time in local time zone.
    return $date->format('m/d/Y H:i:s.v T');
}

/*
 * getJobStatuses - Pull the 'systemJobStatus' table from Alma.
 *                  Will cache the list of JobStatuses in a .cache.codetable.systemJobStatus file.
 *
 * input:
 *      $client     - Alma client handle.
 *
 * output:
 *      array()     - Array of job statuses with code and description of each status.
 */
function getJobStatuses ($client)
{
    # CodeTable to pull from Alma.
    # See: https://developers.exlibrisgroup.com/blog/almas-code-tables-api-list-of-code-tables/
    $codetable = "systemJobStatus";

    # Array to store the list of current job statuses:
    $jobstatuses = array();

    # File to cache array of jobs:
    $jobstatuses_cache = ".cache.codetable.$codetable";

    # Get List of Jobs either by cache or directly from Alma.
    if (file_exists($jobstatuses_cache) && (filemtime($jobstatuses_cache) > (time() - 60 * 1440 ))) {
        # Via Cache.
        # Retrieve list of jobs from the file Cache;
        $jobstatuses = unserialize(file_get_contents($jobstatuses_cache));
    } else {
        # Via Alma.
        # Retrieve current list of jobs from Alma directly.
        $ct = $client->codetables->get($codetable);
        $rows = $ct->{'row'};

        # Iterate through the list of job statuses and load into the array.
        #foreach ($rows as $row) {
        #    array_push($jobstatuses, array('code' => $row->{'code'},'description' => $row->{'description'}));
        #}
        foreach ($rows as $row) {
            $jobstatuses[$row->{'code'}] = $row->{'description'};
        }

        # Store the array into the cache file.
        file_put_contents($jobstatuses_cache, serialize($jobstatuses), LOCK_EX);
    }

    # Return the array.
    return($jobstatuses);
}

?>
