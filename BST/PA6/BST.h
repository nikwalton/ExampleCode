#pragma once

#include"BSTNode.h"
#include<fstream>
#include<string>

using std::ifstream;

template <typename T, typename T2>
class BST {
public:
	BST() {
		this->pRoot = nullptr;
		this->insert("root", '^');
		this->readFile();
	}
	void insert(string const &morse, char const &let);
	void inOrder();

	void readFile();
	string search(char key);
	void textToMorse();
	BSTNode<T, T2> *getRoot() const;

	ifstream inFile;
private:
	BSTNode<T, T2> *pRoot;
	string search(BSTNode<T, T2> *pTree, char key);
	void insert(BSTNode<T, T2> *pTree, string morse, char let);
	void inOrder(BSTNode<T, T2> *pTree);
};

template<typename T, typename T2>
BSTNode<T, T2> * BST<T, T2>::getRoot() const {
	return this->pRoot;
}

template<typename T, typename T2>
void BST<T,T2>::insert(string const &morse, char const &let) {
	insert(this->pRoot, morse, let);
}

template <typename T, typename T2>
void BST<T,T2>::insert(BSTNode<T, T2> *pTree, string morse, char let) {
	if (pTree != nullptr) {
		if (let > pTree->getLetter()) {
			if (pTree->getRight() == nullptr) {
				pTree->setRight(new BSTNode<T, T2>(let, morse));
			}
			else {
				insert(pTree->getRight(), morse, let);
			}
		}
		else if (let < pTree->getLetter()) {
			if (pTree->getLeft() != nullptr)
			{
				insert(pTree->getLeft(), morse, let);
			}
			else {
				pTree->setLeft(new BSTNode<T, T2>(let, morse));
			}
		}
	}
	else {
		this->pRoot = new BSTNode<T, T2>(let, morse);
	}
}

template<typename T, typename T2>
void BST<T, T2>::inOrder() {
	inOrder(this->getRoot());
}

template<typename T, typename T2>
void BST<T, T2>::inOrder(BSTNode<T, T2> *pTree) {
	if (pTree != nullptr) {
		inOrder(pTree->getLeft());
		cout << pTree->getLetter() << endl;
		inOrder(pTree->getRight());
	}
}

template<typename T, typename T2>
void BST<T, T2>::readFile() {
	char letter;
	string morseCode;
	int i;
	inFile.open("MorseTable.txt");
	while(!inFile.eof()) {
		i = 0;
		inFile >> letter;
		inFile >> morseCode;
		this->insert(morseCode, letter);
	}
	inFile.close();
}

template<typename T, typename T2>
string BST<T, T2>::search(BSTNode<T, T2> *pTree, char key) {
	if (pTree->getLetter() == key) {
		return pTree->getMorseCode();
	}
	if (pTree->getLetter() < key) {
		return search(pTree->getRight(), key);
	}
	return search(pTree->getLeft(), key);
}

template<typename T, typename T2>
string BST<T, T2>::search(char key) {
	return search(this->getRoot(), key);
}

template<typename T, typename T2>
void BST<T, T2>::textToMorse() {
	char letter;
	string morse;
	inFile.open("convert.txt");
	while (inFile.get(letter)) {
		if (letter == '\n') {
			cout << "\n";
			continue;
		}
		else if (letter == ' ') {
			continue;
		}
		letter = toupper(letter);
		morse = search(letter);
		cout << morse << "   ";
		
	}
	inFile.close();
}