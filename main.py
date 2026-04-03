import subprocess

def run_core(cmd):
    result = subprocess.getoutput(f"../build/core {cmd}")
    print(result)

def show_help():
    print("""
Commands:
  hello        -> test
  cpu          -> cpu cycles
  add x y      -> add numbers
  ls           -> list files
  exit         -> quit
""")

show_help()

while True:
    user = input(">> ")

    if user == "exit":
        break

    if user == "help":
        show_help()
        continue

    run_core(user)
                                 
