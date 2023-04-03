# Alma_Jobs  ##DRAFT##

Utilities to run an Alma Job from a command line.

## Script

**almajob** - Combined command that encapsulates all of the above.

SYNOPSIS
========

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

:  Sets the function to be run for the almajob script.

--env

:  Sets the Alma environment you will be runing the almajob command against.  This is either 'sandbox' or 'production'.

--job

:  This is the name of the Alma job surrounded by quotes if there are spaces in the name of the job. 

--id

:  This is the instance id number associated with the job.  This uniquely defines each run of the job.  This is equivalent to the "Process ID" in the Admin -> Monitor Jobs interface.


FILES
=====
*almajob.ini*
:  Contains the API keys needed for both environments plus the domain in which you will be running the API calls from. Copy from almajob.ini.sample and update as needed for your environment.

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


AUTHOR
======
Brian Gregg <bdgregg@pitt.edu> at the University of Pittsburgh, University Library System (ULS).




