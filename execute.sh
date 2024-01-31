exercise_index=$1
compile_options=$2
compile_extra_args=$3

exercise_folder='src/exercise_'$exercise_index

if [ "$compile_options" == "compile" ]; then
  code_file=$(ls -a $exercise_folder | grep -i '.cc')
  gpp $compile_extra_args $exercise_folder'/'$code_file -o $exercise_folder'/.exe'
fi

time $exercise_folder'/.exe'