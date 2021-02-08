import os
import shutil
 
def createFolder(directory):
    try:
        if not os.path.exists(directory):
            os.makedirs(directory)
        else:
            print("dist 폴더가 이미 있습니다.")
            exit()
    except OSError:
        print ('Error: Creating directory. ' +  directory)


shutil.copytree("dlls", "dist")
shutil.copy("./build/src/add-mods.exe", "./dist")
# createFolder("packs")