#Hatcher, David
input="poem.txt"
lines=$1
word=$2
folder=./result
file=./result/output.txt
if test -d "$folder"; then
	if test -f "$file"; then
		rm $file
	fi
	rmdir $folder
fi
mkdir "$folder" 
touch "$file"
total_lines=$(cat $input | wc -l)
tail -n $(($total_lines - $lines)) $input > "$file" 
head -n $lines $input >> "$file"
echo "" >> "$file"
word_count=$(head -n $lines $file | grep -o $word | wc -l)
echo "\""$word"\" occurs $word_count times in the first $lines lines of this file" >> "$file"
