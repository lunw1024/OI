import glob, os, shutil

files = glob.glob("*.cpp")

for file in files:
    
    contest = file[:-5].lower()
    name = file[-5:].lower()

    if not os.path.exists(contest):
        os.mkdir(contest)
    print(f"{file}, {contest}, {name}")
    os.rename(file, name)
    shutil.move(name, contest)
