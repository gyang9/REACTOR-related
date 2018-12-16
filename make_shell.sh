#!/bin/sh

workdir=`pwd`

#mkdir -p shell

source ~/work/my_setup.sh

for dm in `seq 0 50` ; do
    for st in `seq 0 50`; do    
        cat > shell/run-$dm-$st.sh <<EOF
#!/bin/bash

source ~/work/my_setup.sh
#export ATMPD_ROOT=$ATMPD_ROOT
#export SKOFL_ROOT=$SKOFL_ROOT
#export LD_LIBRARY_PATH=$LD_LIBRARY_PATH

#source /disk01/usr5/gyang/REACTOR-related/makeApp
#/disk01/usr5/gyang/REACTOR-related/app $dm $st
./app $dm $st

EOF
    
        chmod +x shell/run-$dm-$st.sh
    done
done
