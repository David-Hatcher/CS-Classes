#Hatcher, David
input="poem.txt"
echo "From line $1 to line $2:"
head -n $2 $input | tail -n $(($2 - $1 + 1)) | cat -