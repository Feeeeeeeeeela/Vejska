import subprocess

args = ['https://www.youtube.com/watch?v=v2mqzR_hlT4','--output','pokus.mp4','--start','2023-02-14T18:05','--end','2023-02-14T19:45']
print(args)
subprocess.run(['python','yt_ddl.py'] + args)


