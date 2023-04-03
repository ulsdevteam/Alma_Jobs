# Alma_Jobs 

Utilities to run an Alma Job from a command line.

## Scripts
**almajoblist** - Used to list all jobs available for the Alma environment.

**almajobrun** - Used to execute an Alma job remotely given the name of the job from almajoblist.

**almajobstatus** - Used to determine the status of an Alma job that has been run.

**almajob** - Combined command that encapsulates all of the above.

SYNOPSIS
========

| **almajoblist** \[**--env** {sandbox|production}\]


DESCRIPTION
===========

In general there are parameters used for all three utilities:

--env - This will either be "production" or "sandbox" and are the only two choices for this option.

--name - This is the name of the job listed by the almajoblist command and is needed for the almajobrun and almajobstatus commands.

--instance - This is the instance (Process ID) of the job that was run.  This is a unique identifier for the run of the job.

Options
-------

--env
:  Sets the Alma environment you will be runing the command against.  This is either 'sandbox' or 'production'.

--job
:  This is the name of the Alma job as listed surrounded by quotes if there are spaces in the name of the job.


FILES
=====
*almajob.ini*
:  Contains the API keys needed for both environments plus the domain in which you will be running the API calls from.

*.cache.jobs.sandbox*
:  Contains the cached list of Alma jobs for the Alma sandbox environment.

*.cache.jobs.production*
:  Contains the cached list of Amla jobs for the Alma production environment.


BUGS
====



AUTHOR
======
Brian Gregg <bdgregg@pitt.edu>




