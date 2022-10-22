# Makefileの絶対パス
ROOT_PATH = $(dir $(realpath $(firstword $(MAKEFILE_LIST))))
BIN_PATH = $(ROOT_PATH)bin/

# コンパイラ
CC = g++

# 実行ファイル生成
%: 
	$(CC) -o $(BIN_PATH)$@ $(ROOT_PATH)$@.cpp -std=c++11

