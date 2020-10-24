import sys

# https://www.openbookproject.net/py4fun/mm/assembler.html
# https://hackaday.io/project/10576-mucpu-an-8-bit-mcu/log/36010-writing-an-assembler-in-python

def get_arguments():
    target_filename = sys.argv[1]
    ouput_filename = sys.argv[2]
    return target_filename, ouput_filename

def read_file(filename):
    with open(filename, "r") as f:
        program = list(f.readlines())
    filtered_program = []
    for line in program:
        if line.endswith("\n"):
            line = line[:-1]
        filtered_program.append(line)
        print(line)
    print(program)
    print(f"The program has {len(filtered_program)} lines.")
    return filtered_program

def save_file(name):
    pass

def pass1():
    pass

def pass2():
    pass

def main():
    target_filename, output_filename = get_arguments()
    target_program = read_file(target_filename)
    pass1()
    pass2()


if __name__ == "__main__":
    main()