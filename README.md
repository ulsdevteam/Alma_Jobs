# Alma_Jobs  ##DRAFT##

Utilities to run an Alma Job from a command line.

## Scripts
**almajoblist** - Used to list all jobs available for the Alma environment.

**almajobrun** - Used to execute an Alma job remotely given the name of the job from almajoblist.

**almajobstatus** - Used to determine the status of an Alma job that has been run.

**almajob** - Combined command that encapsulates all of the above.

SYNOPSIS
========

**almajoblist** \[**--env** {sandbox|production}\]

**almajobrun** \[**--env** {sandbox|production}\] \[**--job** {Job Name}\]

**almajobstatus** \[**--env** {sandbox|production}\] \[**--job** {Job Name}\] \[**--id** {Job instance id number}\]

**almajob** \[**--env** {sandbox|production}\] \[**--cmd** {list|run|status}\] 

If **--cmd** = list, no other options are required.

If **--cmd** = run, then \[**--job** {Job Name}\] is required.

If **--cmd** = status, then both \[**--job** {Job Name}\] and \[**--id** {Job instance id number}\] is required.


DESCRIPTION
===========

These scripts allow for the interaction and execution of Alma jobs against either the Alma sandbox or Alma production instances.  

When each of the above scripts are run, there is an initial call to pull down the current list of jobs into cache files.  The cache files are kept for 24 hours before being refreshed at the next script run.  

Options
-------

--cmd

:  Sets the function to be run for the alma_job script.

--env

:  Sets the Alma environment you will be runing the command against.  This is either 'sandbox' or 'production'.

--job

:  This is the name of the Alma job as listed surrounded by quotes if there are spaces in the name of the job. 

--id

:  This is the instance id number associated with the job.  This uniquely defines each run of the job.  This is equivalent to the "Process ID" in the Admin -> Monitor Jobs interface.


FILES
=====
*almajob.ini*
:  Contains the API keys needed for both environments plus the domain in which you will be running the API calls from.

*.cache.jobs.sandbox*
:  Contains the cached list of Alma jobs for the Alma sandbox environment.

*.cache.jobs.production*
:  Contains the cached list of Amla jobs for the Alma production environment.

*.cache.codetable.systemJobStatus*
:  Contains the cached list of the sysytemJobStatus table.


BUGS
====



AUTHOR
======
Brian Gregg <bdgregg@pitt.edu>




