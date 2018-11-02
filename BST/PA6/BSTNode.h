#pragma once
#include<stdlib.h>
#include<iostream>

using std::string;
using std::cout;
using std::endl;

template <typename T, typename T2>
class BSTNode {
public:
	BSTNode(T letter, T2 morseCode) {
		this->MorseCode = morseCode;
		this->Letter = letter;
		this->pLeft = nullptr;
		this->pRight = nullptr;
	}
	~BSTNode() {
		cout << "Inside the BST Node Destructor" << endl;
	}

	BSTNode<T, T2> *getRight() const {
		return this->pRight;
	}
	BSTNode<T, T2> *getLeft() const {
		return this->pLeft;
	}
	
	void setRight(BSTNode<T, T2> *const &newRight) {
		this->pRight = newRight;
	}
	void setLeft(BSTNode<T, T2> *const &newLeft) {
		this->pLeft = newLeft;
	}

	void setMorse(T2 morseCode) {
		this->MorseCode = morseCode;
	}
	void setLetter(T letter) {
		this->Letter = letter;
	}

	T2 getMorseCode() const {
		return this->MorseCode;
	}
	T getLetter() const {
		return this->Letter;
	}

	

private:
	T Letter;
	T2 MorseCode;

	BSTNode *pRight;
	BSTNode *pLeft;
};





