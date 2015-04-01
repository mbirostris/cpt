import sys                                                                                                                                                                                                                                                                             
import os
import math
from tempfile import mkstemp
from shutil import move
from shutil import copyfile
from os import remove, close
import os.path




def replace(file_path, pattern, subst):
    fh, abs_path = mkstemp()
    with open(abs_path,'w') as new_file:
        with open(file_path) as old_file:
            for line in old_file:
                new_file.write(line.replace(pattern, subst))

    close(fh)
    #Remove original file
    remove(file_path)
    #Move new file
    move(abs_path, file_path)

plik=str(sys.argv[1]);

fname = './plugins/'+plik+'.cc'

if not os.path.isfile(fname):
    copyfile('./bin/producer', fname)
    replace(fname, 'XXX', plik)
else:
    print("file exist");


