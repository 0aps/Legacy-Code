SET /a VAR=0 
SET /a VAR2=0 

:HOME 
SET /a VAR=VAR+1 
 
IF %VAR%==100 goto :wait
 
start chat_client.exe 186.150.16.135 11000 
 
goto :HOME 
 
:wait
ping 1.1.1.1 -n 1 -w 100000 > nul
goto :End

:END
SET /a VAR2=VAR2+1 

taskkill /f /im chat_client.exe
 
IF %VAR2%==100 goto :FEND

:FEND
exit 
 
