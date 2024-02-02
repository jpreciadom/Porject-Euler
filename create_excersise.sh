exercise_index=$1
exercise_name=$2

reg=$exercise_name
reg=${reg,,}
reg=${reg// /_}

exercise_folder='src/exercise_'$exercise_index
exercise_file_name=$exercise_index'_'$reg'.cpp'
exercise_file_path=$exercise_folder'/'$exercise_file_name
echo 'Creating file '$exercise_file_path

mkdir $exercise_folder

# It creates the .c file
echo '#include <iostream>' > $exercise_file_path
echo '#include <string>' >> $exercise_file_path
echo '' >> $exercise_file_path
echo 'using namespace std;' >> $exercise_file_path
echo '' >> $exercise_file_path
echo 'int main() {' >> $exercise_file_path
echo '    string exercise_name = "'$exercise_name'";' >> $exercise_file_path
echo '    long answer = 0;' >> $exercise_file_path
echo '' >> $exercise_file_path
echo '    // Your code goes here' >> $exercise_file_path
echo '    ' >> $exercise_file_path
echo '    // Your code ends here' >> $exercise_file_path
echo '' >> $exercise_file_path
echo '    cout << exercise_name << endl;' >> $exercise_file_path
echo '    cout << "Answer: " << answer << endl;' >> $exercise_file_path
echo '    return 0;' >> $exercise_file_path
echo '}' >> $exercise_file_path
echo '' >> $exercise_file_path
