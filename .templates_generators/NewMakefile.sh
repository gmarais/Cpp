if [ -n "$1" ]; then
	echo -e "\033[1;30mGenerating c++ Makefile for : $1\033[1;32m";
	ExecName="{ExecName}"
	a1="$1"
	dateTime=$(date +"%Y\/%m\/%d %H:%M:%S")
	sed s/"{date}"/"$dateTime"/g ~/.templates_generators/templates/header_42.makefile > ./Makefile;
	sed s/{ExecName}/$a1/g ~/.templates_generators/templates/Makefile >> Makefile;
	sources=$(ls ./ | grep ".cpp";ls ./classes | grep ".cpp" | awk '$0="classes\\/"$0')
	isEndl="";
	for line in $sources
	do
		if [ -z "$isEndl" ]; then
			sed -i.bak s/"{sources}"/"$line{sources}"/g ./Makefile >> ./Makefile;
			rm ./Makefile.bak;
		else
			sed -i.bak s/"{sources}"/" \\\\\n$line{sources}"/g ./Makefile >> ./Makefile;
			rm ./Makefile.bak;
		fi
		isEndl="true";
	done
	sed -i.bak s/"{sources}"/""/g ./Makefile >> ./Makefile;
	rm ./Makefile.bak;
	echo -e "$a1's Makefile created!\033[0;0m";
else
	echo -e "\033[1;31mUsage :\033[0;0m NewMakefile [executable name]";
fi
