exercise_index=$1
exercise_name=$2

reg=$exercise_name
reg=${reg,,}
reg=${reg// /_}

exercise_folder='src/exercise_'$exercise_index
exercise_file_name=$exercise_index'_'$reg'.c'
exercise_file_path=$exercise_folder'/'$exercise_file_name
echo 'Creating file '$exercise_file_path

mkdir $exercise_folder

# It creates the .c file
echo '#include <stdio.h>' >> $exercise_file_path
echo '' >> $exercise_file_path
echo 'int main() {' >> $exercise_file_path
echo '    char *exercise_name = "'$exercise_name'";' >> $exercise_file_path
echo '    long answer = 0;' >> $exercise_file_path
echo '' >> $exercise_file_path
echo '    // Your code goes here' >> $exercise_file_path
echo '    ' >> $exercise_file_path
echo '    // Your code ends here' >> $exercise_file_path
echo '' >> $exercise_file_path
echo '    printf("%s\n", exercise_name);' >> $exercise_file_path
echo '    printf("Answer: %ld\n", answer);' >> $exercise_file_path
echo '    return 0;' >> $exercise_file_path
echo '}' >> $exercise_file_path