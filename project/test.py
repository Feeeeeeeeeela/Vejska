import subprocess

args = ['https://www.youtube.com/watch?v=8tlzx5Wuy8s','--output','05mechanika.mp4','--start','2023-02-20T14:00','--end','2023-02-20T15:50']
print(args)
subprocess.run(['python','yt_ddl.py'] + args)


 