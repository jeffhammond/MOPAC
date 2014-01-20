#
##########################SYSTEM SPECIFIC VARIBLES######################
##########please change to suit your local setup. ######################
#set echo verbose
#set echo verify
#
#  First, lets define all system specific variables
#
#  The location of this file and the executable.
set mopacdir = /usr/users/stewart/mopac6
#
#  The name of the "normal" mopac executable.  (commonly the small version)
set smallmopac = MOPAC
#
#  The name of the "alternate" mopac executable.  (the larger version)
set bigmopac = MOPACBIG
#
#
#########################END OF SYSTEM SPECIFIC DEFINITIONS#############
#
#   This is actually a compilation of several individual .csh files into
#     a single larger .csh file.  Before, each of the files would be called
#     in turn.  Now, the name of the individual .csh files is simply the 
#     first argument in the call to this master file.  The job name has
#     been slipped to the second argument.  This has been done to ease 
#     installation and periodic updates by reducing the number of separate
#     files to change to a single one.  This also reduces the number of 
#     files that must be updated to just one since all the variables defined
#     once at the top and then used throughout the rest of the script.
#     NOTE:  If you wish to split this file into the smaller .csh files, it
#     will require substanital altering of the code.  It is not an easy 
#     process.  FJSRL will support the present form only.
#
#  To activate this .csh file, add the line 
#    " source csh mopac.csh "
#        to your .cshrc file.
#
# set echo verify
# 
#-------------------------------------------------------------------------
#
#  This script was written at the US Air Force Academy, Frank J. Seiler
#    Research Laboratory for use on a DECStation 3100.  It is a generic 
#    ULTRIX/UNIX csh script that should be easily adapted to other UNIX
#    systems.  For assistance please contact:
#
#        Dr. Michael B. Coolidge
#        FJSRL/NC
#        USAFA CO 80840
#        (719)472-2655
#
#  ARPA net address:  Coolidge@usafa.af.mil
#
#-------------------------------------------------------------------------
#
#  Now, lets get the two possible arguments that can be specified assigned.
set type = $1
set job = $2
#
#  Now, to go to the correct section of code as determined by the first\
#    argument given.  Note:  if no argument is given, assume it should
#    be startup.
#
if ( a$type == asubmit )      goto submit
if ( a$type == aqueue )       goto queue
if ( a$type == acleanup )     goto cleanup
if ( a$type == aimopac )      goto imopac
if ( a$type == armopac )      goto rmopac
if ( a$type == achkmopac )    goto chkmopac
if ( a$type == ashut )        goto shut
if ( a$type == a )            goto setupmopac
if ( a$type == asetupmopac )  goto setupmopac
#
echo  Warning, your first argument is not a valid choice
#
exit
#
#---------------------start of setupmopac.csh---------------------------
setupmopac:
#  This portion will take care of all aliases needed in order to run MOPAC.
#
#-------------------------------------------------------------------------
#
#  Use the next command to run a job in background 'mopac filename'
alias mopac '$mopacdir/mopac.csh imopac \!*'
#
#  The next command allows you to stop a currently running mopac job.
#    Once in the same directory as the running job, type:  'shut filename'
#
alias shut  '$mopacdir/mopac.csh shut'
#
#  This commands gives a directory of all output files
alias dout   'ls -tl *.out |  more '
#
#  The next series of commands are for a pseudo batch queue.  This queue
#    system uses the four portions of this file, 'submit', 'queue', 'cleanup',
#    and 'chkmopac' and creates or uses three more '.qlock', '.qdone', 
#    and '.qjobs'.  The queue is managed by queue.csh.  Jobs are placed 
#    onto the queue by submit by adding the current path, username,
#    and filename to the end of .qjobs.  After a single job is completed,
#    cleanup compares the list of files to do, .qjobs, with the list
#    of files that have completed, .qdone, and deletes all finished jobs
#    from both lists.  The function of chkmopac is to check the system
#    for a currently running queue.  If that queue does not exist, then
#    chkmopac will start it.  If it does, then do not start a second one.
#    The file .qlock contains the name of the currently executing file.
#    If the name listed is 'waiting', then there is not a job current running.
#    The queue is waiting for a new job to be submitted.  Once a job is
#    submitted, then the queue will be restarted.
#
#  To submit a job to the queue, type: 'submit filename'
alias submit 'csh $mopacdir/mopac.csh submit \!*'
#
#  To restart the queue after a crash, type: 'startmopac'
alias startmopac 'csh $mopacdir/mopac.csh chkmopac'
#
#  To check what is currently running, type: 'doing'
alias doing 'more $mopacdir/.qlock'
#
#  To check what is currently on the queue, type: 'todo'
alias todo 'more $mopacdir/.qjobs'
#
#  Note: The order jobs are executed on the queue can be changed at
#    anytime by simply editing the file $mopacdir/.qjobs.  The only
#    job that cannot be affected is the currently executing one.
exit
#----------------------------end of setupmopac.csh----------------------
#
#----------------------------start of submit.csh------------------------
submit:
#  This will setup a pseudo batch queue.  By typing submit 'jobname',
#    that job will be entered into a holding file along with the current
#    path name.  Before the job is entered though, it will be checked to
#    see that it is valid.
#  This will also check to see if the batch queue has been started.  If not,
#    the queue will be started. 
#
#  set echo verbose
#
#  Check to see if the queue is presently running.  If not, start it.
csh $mopacdir/mopac.csh chkmopac &
#  
#  Now, parse the job name and store it in the correct format in .qjobs
set pname = $cwd
set rname = $job:r
set ename = $job:e
set owner = `whoami`
#
if !(-e $rname.dat) goto warn
echo $pname/$owner/$rname >> $mopacdir/.qjobs
exit
#
warn:
#  The input file did not exist.  Warn the user.
echo The file $rname.dat did not exist.  Your job is not submitted
exit
#------------------------------end of submit.csh------------------------
#
#----------------------------start of queue.csh-------------------------
queue:
#----------------------------------------------------------
# set echo verbose
# code to establish a pseudo batch queue ...
#
#----------------------------------------------------------
# don't go on if there's already a job executing
#----------------------------------------------------------
if -e $mopacdir/.qlock goto doing
#
#  entry point to start a new run
nextone:
echo queue is running >> $mopacdir/.qlock
#
#  do a cleanup
csh $mopacdir/mopac.csh cleanup
#
#  Now, setup the rest of the needed variables
#
set job = locked
#----------------------------------------------------------
# loop over the jobs in qjobs and start the first one that
# has not completed yet.  upon completion, jobs copy the job
# name into file qdone
#----------------------------------------------------------
set njobs = `wc -l < $mopacdir/.qjobs`
set nleft = $njobs
#
if "$nleft" == 0 then
echo waiting >> $mopacdir/.qlock
#
#  if this queue should now wait, then put it to sleep.  Otherwise
#    exit.  (uncomment the desired option)
exit
#sleep 300
if -e $mopacdir/.qlock rm $mopacdir/.qlock
goto nextone
endif
#
while "$nleft" != 0
set njob = `expr $njobs - $nleft + 1`
#
#  every tenth job, do a cleanup
if "$njob" == 10 csh $mopacdir/mopac.csh cleanup
#
set job = `sed -n "$njob"p $mopacdir/.qjobs`
if "$job" == quit then
if -e $mopacdir/.qlock rm $mopacdir/.qlock
exit
endif
if "$job" == done then
#
#  if this queue should now wait, then put it to sleep.  Otherwise
#    exit.  (uncomment the desired option)
exit
#sleep  300
goto nextone
endif
#  now, to separate the job name from the path name
#
set full = $job
set pname = $full:h
set owner = $pname:t
set pname = $pname:h
set job = $full:t
if ( $job == $pname ) set pname = "."
#
#
set idone = `grep $job.is $mopacdir/.qdone | wc -l`
if "$idone" != 0 goto nogoodq
# 
#set echo verbose
#
echo $job >> $mopacdir/.qlock
#
#  Now, execute the mopac job
#
#
chdir $pname
#
#  Next, see if job.dat exists.  If not, goto helpmessage
if -z $job.dat goto helpmessageq 
#
#  Check $job.dat to see if this is a nextrun job.  
set restart1 = `head -3 $job.dat | grep -i " restart"  | wc -l`
set restart2 = `head -3 $job.dat | grep -i " oldens"  | wc -l`
set restart = `expr "$restart1" + "$restart2" `
if ($restart != 0) then
  if !(-e $job.den) goto norestartq
  if($restart1 != 0) then
    if !(-e $job.res) goto norestartq
  endif
else
  foreach file (res den)
        if -e $job.$file mv $job.$file $job.$file.$$
  end
endif
#
#  Check that prior copies of files do not exist
foreach file (out log arc end)
    if -e $job.$file mv $job.$file $job.$file.$$
  end
#
#  Now, make all the necessary assignments
setenv FOR005 $job.dat
setenv FOR006 $job.out
setenv FOR009 $job.res
setenv FOR010 $job.den
setenv FOR011 $job.log
setenv FOR012 $job.arc
setenv FOR013 $job.gpt
setenv FOR016 $job.syb
setenv FOR020 $job.ump
setenv SETUP  SETUP.DAT
setenv SHUTDOWN $job.end
if -e core rm core
if -e fort.2 rm fort.2
if -e fort.16 rm fort.16
nice -8 $mopacdir/$smallmopac >> $job.log 
set iok1 = `tail -1 "$job.out" | grep "IN SYSTEM" | wc -l`
set iok2 = `tail -1 "$job.out" | grep "ATOMS ALLOWED" | wc -l`
set iok3 = `tail -1 "$job.out" | grep "MAXIMUM ALLOWED" | wc -l`
set iok = `expr "$iok1" + "$iok2" + "$iok3" `
if $iok == 1 then
    set idone2 = `grep "== MOPAC DONE ==" "$job.out" | wc -l`
    if $idone2 == 0 then
check:
      set nobig = `ps ax | grep "$mopacdir" | grep "/$bigmopac" | wc -l`
        if $nobig != 0 sleep 300 
        if $nobig != 0 goto check
            rm $job.out
            rm $job.log
            time $mopacdir/$bigmopac >> $job.log
    endif
endif
chown $owner $job.*
echo $job is done >> $mopacdir/.qdone
if -e core rm core
if -e fort.2 rm fort.2
if -e fort.16 rm fort.16
#  this job has completed normally
#
if -e SHUTDOWN rm SHUTDOWN
if -e $job.end rm $job.end
goto nextrun 
#
helpmessageq:
#  the file specified on the command line either did not exist or has
#     zero length
echo 'Your file either does not exist or has zero length'
echo $job is not done >> $mopacdir/.qdone
#
goto nextrun 
#
norestartq:
#  A nextrun has been specified but the .res or .den files do not exist
echo 'I cannot find either "$job".den or "$job".res.  Please help'
echo $job is not done >> $mopacdir/.qdone
#
goto nextrun 
#
#
nextrun:
if -e $mopacdir/.qlock rm $mopacdir/.qlock
#
set nleft = `expr $nleft - $nleft + 1`
# 
nogoodq:
set nleft = `expr $nleft - 1`
end
#  now to cleanup the todo and done lists
csh $mopacdir/mopac.csh cleanup
# 
if -e $mopacdir/.qlock rm $mopacdir/.qlock
echo waiting >> $mopacdir/.qlock
if -e $mopacdir/.qlock rm $mopacdir/.qlock
goto nextone
#
#  now, to do the next one
#
goto nextone
#
doing:
echo there is presently a job running
exit
#--------------------------------------------------------------
# the end.
#--------------------------------------------------------------
#------------------------------end of queue.csh-------------------------
#
#----------------------------start of cleanup.csh-----------------------
cleanup:
#----------------------------------------------------------
#
# set echo verbose
#
# code to look after jobs in the batch queues ...
#  this file automatically cleans up the input list and
#  zero's out the output list.  
#----------------------------------------------------------
#
set njobs = `wc -l < $mopacdir/.qjobs`
set nleft = $njobs
if -e $mopacdir/.qjobs2 rm $mopacdir/.qjobs2
#
if "$nleft" == 0 exit
#
while "$nleft" != 0
set njob = `expr $njobs - $nleft + 1`
set job = `sed -n "$njob"p $mopacdir/.qjobs`
#  now, to separate the job name from the path name
#
set full = $job
set pname = $full:h
set job = $full:t
if ( $job == $pname ) set pname = "."
#
#
set idone = `grep $job.is $mopacdir/.qdone | wc -l`
if "$idone" != 0 goto nogoodm
# 
#
echo $pname/$job >> $mopacdir/.qjobs2
#
# 
nogoodm:
set nleft = `expr $nleft - 1`
end
#
#  now, to do the next one
#
#
if -e $mopacdir/.qjobs rm $mopacdir/.qjobs
if !(-e $mopacdir/.qjobs2) echo   > $mopacdir/.qjobs
if -e $mopacdir/.qjobs2 mv $mopacdir/.qjobs2 $mopacdir/.qjobs
if -e $mopacdir/.qdone rm $mopacdir/.qdone
echo this file has been cleaned > $mopacdir/.qdone
chmod +w $mopacdir/.qjobs
chmod +w $mopacdir/.qdone
exit
#------------------------------end of cleanup.csh-----------------------
#
#----------------------------start of mopac.csh-------------------------
imopac:
#
# A csh file that will assign all the necessary variables to run MOPAC
#
# set echo verbose
#
#	If filename is missing, or are the names 'help' or 'h', then
#		the help facility will be invoked.
#
#-------------------------------------------------------------------------
#
#  First, set the job to be executed to the variable 'job'
set full = $job
set job = $full:r
set ext = $full:e
if (null$ext == null) set ext = dat 
if (null$ext == null$full) set ext = dat 
#
#  Next, see if job is blank, h, or help
if (null$job == null) goto help
if (null$job == nullh) goto help
if (null$job == nullhelp) goto help
#  Next, see if job.dat exists.  If not, goto helpmessage
if ( $ext != dat ) goto datmessage
#
if !(-e $job.dat) goto helpmessagem 
if -z $job.dat goto helpmessagem 
#
#  Check $job.dat to see if this is a restart job.  
set restart1 = `head -3 $job.dat | grep -i " restart"  | wc -l`
set restart2 = `head -3 $job.dat | grep -i " oldens"  | wc -l`
set restart = `expr "$restart1" + "$restart2" `
if ($restart != 0) then
  if !(-e $job.den) goto norestartm
  if($restart1 != 0) then
    if !(-e $job.res) goto norestartm
  endif
else
  foreach file (res den)
        if -e $job.$file mv $job.$file $job.$file.$$
  end
endif
#
#  Now, to execute MOPAC 
csh $mopacdir/mopac.csh rmopac $job &
exit
#
help:
#  run the help program since either no filename was given, or the file name
#    given was h or help
set hold = $cwd
chdir $mopacdir
$mopacdir/HELP
chdir $hold
#
exit
datmessage:
#  the extension given was not .dat
echo 'Your filename did not have a .dat extension'
echo   ' but a ' $ext ' extension'
#
exit
#
helpmessagem:
#  the file specified on the command line either did not exist or has
#     zero length
echo 'Your file either does not exist or has zero length'
#
exit
#
norestartm:
#  A restart has been specified but the .res or .den files do not exist
echo 'I cannot find either "$job".den or "$job".res.  Please help'
#
exit
#
#------------------------------end of imopac.csh-------------------------
#
#----------------------------start of rmopac.csh------------------------
rmopac:
#
# set job = $1
#
# set echo verbose
#
#  Check that prior copies of files do not exist
foreach file (out log arc end)
    if -e $job.$file mv $job.$file $job.$file.$$
  end
#
#  Now, make all the necessary assignments
#
setenv FOR005 $job.dat
setenv FOR006 $job.out
setenv FOR009 $job.res
setenv FOR010 $job.den
setenv FOR011 $job.log
setenv FOR012 $job.arc
setenv FOR013 $job.gpt
setenv FOR016 $job.syb
setenv FOR020 $job.ump
setenv SETUP  SETUP.DAT
setenv SHUTDOWN $job.end
if -e core rm core
if -e fort.2 rm fort.2
if -e fort.16 rm fort.16
time $mopacdir/$smallmopac >> $job.log  
set iok1 = `tail -1 "$job.out" | grep "IN SYSTEM" | wc -l`
set iok2 = `tail -1 "$job.out" | grep "ATOMS ALLOWED" | wc -l`
set iok3 = `tail -1 "$job.out" | grep "MAXIMUM ALLOWED" | wc -l`
set iok = `expr "$iok1" + "$iok2" + "$iok3" `
if $iok == 1 then
    set idone2 = `grep "== MOPAC DONE ==" "$job.out" | wc -l`
    if $idone2 == 0 then
      set nobig = `ps ax | grep "$mopacdir" | grep "/$bigmopac" | wc -l`
        if $nobig == 0 then
            rm $job.out
            rm $job.log
            time $mopacdir/$bigmopac >> $job.log
          else
            rm $job.out
            rm $job.log
            echo $job must be submitted to batch queue since there is
            echo      currently a big job running.
        endif
    endif
endif
echo job $job is finished
head -3 $job.dat
if -e core rm core
if -e fort.2 rm fort.2
if -e fort.16 rm fort.16
#  this job has completed normally
#
if -e SHUTDOWN rm SHUTDOWN
if -e $job.end rm $job.end
if -e nul      rm nul
exit
#
#------------------------------end of rmopac.csh------------------------
#
#----------------------------start of chkmopac.csh----------------------
chkmopac:
#  This will check if a job is running.  If not, startup the mopac queue.
#    Note: It is necessary to do the two grep's in order to not get a flase
#    hit with itself or another job of itself running in memory at the same
#    time.
#  The two grep's should together contain the path and file name of the queue
#    handler.  Neither should contain the complete name.
#    
# set echo verbose
#
#  Now, parse the job name and store it in the correct format in .qjobs
set hname = $mopacdir:h
set tname = $mopacdir:t
#
set jobs = `ps ax | grep "csh $hname/" | grep "$tname/mopac.csh queue" | wc -l`
if "$jobs" == 0 then
    if -e  $mopacdir/.qlock rm  $mopacdir/.qlock
    csh  $mopacdir/mopac.csh queue &
  endif
exit
#------------------------------end of chkmopac.csh----------------------
#
#----------------------------start of shut.csh--------------------------
shut:
#
#
#  Now, to parse the job name and possibly remove any extension
# set job = $1
set rname = $job:r
#
if -e $rname.dat goto shut_ok      
echo The file $rname.dat does not exist in this directory
exit
shut_ok:
echo shutting down this job >> $rname.end
exit
#------------------------------end of shut.csh--------------------------
#
#-----------------------------------------------------------------------
