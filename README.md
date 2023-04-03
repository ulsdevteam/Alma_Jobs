# Alma_Jobs 

Utilities to run an Alma Job from a command line.

SCRIPT
======

**almajob** - Combined command that encapsulates all of the following.
**almajoblist** - Lists all of the jobs of an Alma environment.
**almajobrun** - Runs a specified job in the Alma environment.
**almajobstatus** - Obtains the job status of a job in the Alma environment.

SYNOPSIS
========

**almajob** \[**--env** {sandbox|production}\] \[**--cmd** {list|run|status}\] 

If **--cmd** = list, no other options are required.

If **--cmd** = run, then \[**--job** {Job Name}\] is required.

If **--cmd** = status, then both \[**--job** {Job Name}\] and \[**--id** {Job instance id number}\] is required.


DESCRIPTION
===========

These scripts allow for the interaction and execution of Alma jobs against either the Alma sandbox or Alma production instances.  

When the almajob script is run, there is an initial call to pull down the current list of Alma jobs into cache files.  The cache files are kept for 24 hours before being refreshed at the next script run.  Currently it is optional to simply remove the cache files before running the script to force it to re-download the current list of Alma jobs.  


REQUIREMENTS
============
Software Requirements:
- php 5.x or newer.
- php composer 1.x or newer.


INSTALLATION
============
In the folder in which you wish to install Alma_Jobs, change to that folder then run the following:
```shell
git clone https://github.com/ulsdevteam/Alma_Jobs
```

Then, change directory into the Alma_Jobs folder and run the following command:
```shell
composer install
```

Once complete, copy the almajob.ini.sample to almajob.ini and update the file with your production and sandbox API keys.
```shell
cp almajob.ini.sample almajob.ini
vi almajob.ini
```



Options
-------

--cmd

:  Sets the function to be run for the almajob script.  This is one of "list", "run", or "status" referring to the option to simply list the jobs available for the environment or to run one of the jobs, or to obtain the current status of the job and id in question.

--env

:  Sets the Alma environment you will be runing the almajob command against.  This is either 'sandbox' or 'production'.

--job

:  This is the name of the Alma job surrounded by quotes if there are spaces in the name of the job.  For example "ERP export using profile FINANCE".

--id

:  This is the instance id number associated with the job.  This uniquely defines each run of the job.  This is equivalent to the "Process ID" in the Admin -> Monitor Jobs interface.  This tends to be lengthy number.


FILES
=====
*almajob.ini*
:  Contains the API keys needed for both environments plus the domain in which you will be running the API calls from.  There is a sample file included.  Make a copy of the file almajob.ini.sample to almajob.ini and update the file as needed for your environment.

*.cache.jobs.sandbox*
:  Contains the cached list of Alma jobs for the Alma sandbox environment.

*.cache.jobs.production*
:  Contains the cached list of Amla jobs for the Alma production environment.

*.cache.codetable.systemJobStatus*
:  Contains the cached list of the sysytemJobStatus table.


BUGS
====

1. Consider adding changes to where cache files are kept such as "--cache_dir" option.
2. Consider adding an option to force cache updating at the time of the script run such as "--force".
3. Consider adding an option to point to the almajob.ini file at the time of the script run such as "--ini-file".


AUTHOR
======
Brian Gregg <bdgregg@pitt.edu> at the University of Pittsburgh, University Library System (ULS).




