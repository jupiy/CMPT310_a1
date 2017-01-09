############################################
# Xuanbing(Liz) Yan
# StudentNumber: 301295772
# SFU UserName: xya60
# CMPT310 Fall2016 Assignment #1
# Instructor: James Delgrande 
############################################

all: navigation1 navigation2

.SUFFIXES: .h .o .cpp

CCOPTS = -g
LIBS = -lm
OBJS = main1.o main2.o navigation.o
CCEXEC = navigation1 navigation2

navigation1 : main1.o navigation.o
	g++ -o navigation1 main1.o navigation.o
navigation2 : main2.o navigation.o
	g++ -o navigation2 main2.o navigation.o

main1.o : main1.cpp navigation.h
	g++ -c main1.cpp
main2.o : main2.cpp navigation.h
	g++ -c main2.cpp
navigation.o : navigation.cpp navigation.h
	g++ -c navigation.cpp
clean : 
	rm -f navigation1
	rm -f navigation2
	rm -f main1.o
	rm -f main2.o
	rm -f navigation.o


