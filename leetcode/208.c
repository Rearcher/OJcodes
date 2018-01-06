#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct TrieNode {
	char c;
	bool isLeaf;
   	struct TrieNode* sons[26];
};

/** Initialize your data structure here. */
struct TrieNode* trieCreate() {
	struct TrieNode* node = (struct TrieNode*)malloc(sizeof(struct TrieNode));
	node->c = '\0';
	node->isLeaf = false;
	memset(node->sons, 0, sizeof(struct TrieNode*)*26);

	return node;
}

/** Inserts a word into the trie. */
void insert(struct TrieNode* root, char* word) {
	struct TrieNode* node = NULL;
	struct TrieNode** sons = root->sons;
	char *ch = word;

	while (*ch != '\0') {
		struct TrieNode* t = sons[*ch - 'a'];
		if (t == NULL) {
			node = trieCreate();
			node->c = *ch;
			sons[*ch - 'a'] = node;
		} else {
			node = t;
		}

		sons = node->sons;
		ch++;

		if (*ch == '\0')
			node->isLeaf = true;
	}
}

/** Returns if the word is in the trie. */
bool search(struct TrieNode* root, char* word) {
	struct TrieNode* node = NULL;
   	struct TrieNode** sons = root->sons;
   	char* ch = word;

   	while (*ch != '\0') {
		struct TrieNode* t = sons[*ch - 'a'];
		if (t == NULL) return false;
		else node = t;

		sons = node->sons;
		ch++;
	}

	if (node->isLeaf != true)
		return false;

	return true;
}

/** Returns if there is any word in the trie 
    that starts with the given prefix. */
bool startsWith(struct TrieNode* root, char* prefix) {
    struct TrieNode* node = NULL;
	struct TrieNode** sons = root->sons;
	char *ch = prefix;

	while (*ch != '\0') {
		struct TrieNode* t = sons[*ch - 'a'];
		if (t == NULL) return false;
		else node = t;

		sons = node->sons;
		ch++;
	}
	return true;
}

/** Deallocates memory previously allocated for the TrieNode. */
void trieFreeChildren(struct TrieNode* node) {
   	int i;

	if (node->isLeaf == false) {
		for (i = 0; i < 26; ++i)
			if (node->sons[i] != NULL)
				trieFreeChildren(node->sons[i]);
	}

	if (node != NULL)
		free(node);
}

void trieFree(struct TrieNode* root) {
	trieFreeChildren(root);
}

int main() {
	struct TrieNode *root = trieCreate();
	insert(root, "abc");
	
	bool exist = search(root, "abc");
	bool prefix = startsWith(root, "ab");

	printf("%d %d\n", exist, prefix);

	trieFree(root);
}
