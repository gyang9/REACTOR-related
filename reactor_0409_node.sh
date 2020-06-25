#! /usr/bin/env bash

#USERDIR="/pnfs/dune/persistent/users/wbae/CAF2"
#CP="ifdh cp"

source /cvmfs/dune.opensciencegrid.org/products/dune/setup_dune.sh

setup genie v2_12_10c -q e15:prof
setup genie_xsec v2_12_10 -q DefaultPlusValenciaMEC
setup genie_phyopt v2_12_10 -q dkcharmtau
setup dk2nu v01_05_01b -q e15:prof
setup ifdhc

:<<"END"
echo ${PROCESS}
RUNNUMBER=${PROCESS}
echo $RUNNUMBER


USERDIR="/pnfs/dune/persistent/users/wbae/CAF2"
CP="ifdh cp"

source /cvmfs/dune.opensciencegrid.org/products/dune/setup_dune.sh

setup genie v2_12_10c -q e15:prof
setup genie_xsec v2_12_10 -q DefaultPlusValenciaMEC
setup genie_phyopt v2_12_10 -q dkcharmtau
setup dk2nu v01_05_01b -q e15:prof
setup ifdhc

${CP} ${USERDIR}/app3.tar.gz app3.tar.gz

tar -xzf app3.tar.gz
mv app3/* .

chmod +x app_noloop_1free_log
END

RUNNUMBER=1818
for((i=0; i<2601-1818; i++))
do

	
	ds=`echo $((  ${RUNNUMBER}  /  51  ))` #변수 정의 할 때 = 사이에 띄어 쓰기 있으면 안 됨
	dm=`echo $((  ${RUNNUMBER}  %  51  ))`

	RUNNUMBER=`echo $((RUNNUMBER+1))`
       	
	#./app_noloop_16free_log_sys1 `echo $(( ${dm} ))` `echo $(( ${ds} ))` NEOSPROSPECT
	./app_final7_100dm_unpoly `echo $(( ${ds} ))` `echo $(( ${dm} ))` NEOS
	#./app_olddata `echo $(( ${ds} ))` `echo $(( ${dm} ))` NEOS
	#./app_veryolddata `echo $(( ${ds} ))` `echo $(( ${dm} ))` NEOS
        echo `echo $(( ${ds} ))` `echo $(( ${dm} ))` NEOS ${RUNNUMBER}
	#${CP} scan2Dnew_NEOSPROSPECT_fissionFree_ISO0_SYST1_`echo $(( ${dm} ))`_`echo $(( ${ds} ))`.txt ${USERDIR}/scan2Dnew_NEOSPROSPECT_fissionFree_ISO0_SYST0_${RUNNUMBER}.txt
        #${CP} scan2Dnew_NEOS_fissionFree_ISO0_SYST1_`echo $(( ${dm} ))`_`echo $(( ${ds} ))`.txt ${USERDIR}/scan2Dnew_NEOS_fissionFree_ISO0_SYST0_${RUNNUMBER}.txt
	#${CP} scan2Dnew_NEOSPROSEPCT_fissionFree_ISO1_SYST0_`echo $(( ${dm} ))`_`echo $(( ${ds} ))`.txt ${USERDIR}/scan2Dnew_NEOSPROSPECT_${RUNNUMBER}.txt
		
done 
