Try to get a universal U235 correction for Double Chooz, Daya Bay, RENO and NEOS.
Also check if sterile mixing 14 works for above dataset.

compile: g++ -std=c++11 -o app app.cc simple_DC.cc -lRooFit -lHtml -lMinuit -lRooFitCore `root-config --cflags --glibs`
run: ./app

running JUNO stuff:
g++ -std=c++11 -o app app.cc juno.cc -lRooFit -lHtml -lMinuit -lRooFitCore `root-config --cflags --glibs`
./app xxxx


Wonseok : the recent files before trying newBin are "app_final7_iteration2", "app_straight.cc", and "simple_DC_final7_iteration2.cc" 
