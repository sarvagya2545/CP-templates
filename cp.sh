g! /bin/bash
clear

# Read contest site from input
read -p "Select the contest site: 
    1. AtCoder
    2. CodeChef
    3. Codeforces
Enter the corresponding number here: " SITE_INDEX

folders=("AtCoder" "CodeChef" "Codeforces")
NUM_FOLDERS=${#folders[@]}

if [[ $((SITE_INDEX)) -gt NUM_FOLDERS ]]; then
    echo "Invalid number"
    exit 1
fi

clear

SITE="${folders[SITE_INDEX - 1]}"
echo "Site chosen: $SITE"


# After selecting contest site, read the name of the folder for the contest
# E.g. ABC250, 730Div2, Global24, etc.
echo "Enter the name of the contest(E.g. ABC250, 730Div2, Global24, etc.): "
read -p "" CONTEST_NAME

# create the folder with the name
if [ ! -d "$SITE" ]; then
    mkdir "$SITE";
fi

if [ -d "$SITE/$CONTEST_NAME" ]; then
    rm -rf "$SITE/$CONTEST_NAME"
fi

mkdir "$SITE/$CONTEST_NAME"
echo
echo
echo "Folder created: $CONTEST_NAME"

# create problem files with template.cp.cpp as the starting point
read -p "How many problem files should be created? " FILE_COUNT

if [[ FILE_COUNT -gt 26 ]]; then
    echo "Sorry, cannot create more than 26 files"
    exit 1
fi

# Create basic input output files
touch "$SITE/$CONTEST_NAME/input.txt"
touch "$SITE/$CONTEST_NAME/output.txt"
touch "$SITE/$CONTEST_NAME/debug.txt"
cp debug.h "$SITE/$CONTEST_NAME/debug.h"

# loop from 1 to FILE_COUNT
for (( a=1; a<=FILE_COUNT; a++ ))
do
    # Get the file name character
    # https://stackoverflow.com/questions/890262/integer-ascii-value-to-character-in-bash-using-printf
    FILE_CHAR=$(eval printf '%x' $(( a + 64 )) | xxd -p -r)

    # Create the file
    FILE_NAME="$SITE/$CONTEST_NAME/$FILE_CHAR.cpp"
    touch "$FILE_NAME"

    # Copy the C++ template from template
    cp template.cp.cpp "$FILE_NAME"
done

echo "Created all files... Best of luck for contest!"

# Open text editor
code "$SITE/$CONTEST_NAME"
