dosya_adi=$1

if [[ -z $dosya_adi ]]; then
    echo "Lütfen bir dosya adı belirtin."
    exit 1
fi

program_adi="${dosya_adi%.*}"

g++ $dosya_adi -o $program_adi -lopengl32 -lglu32 -lglut32

if [[ $? -eq 0 ]]; then
    echo "Çalışıyor..."
    ./$program_adi
    rm "$program_adi.exe"
else
    echo "Derleme hatası."
fi
