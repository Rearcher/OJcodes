class TrieNode {
public:
	TrieNode *child[26];
	bool is_word;
	TrieNode() : is_word(false){
		memset(child,0,sizeof(child));
	}
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}

	void insert(string word) {
		TrieNode *p = root;
		for(auto i : word) {
			if(!p->child[i-'a'])
				p->child[i-'a'] = new TrieNode();
			p = p->child[i-'a'];
		}
		p->is_word = true;
	}
	
	bool search(string word) {
		TrieNode *p = root;
		for(auto i : word) {
			int index = i - 'a';
			if(!p->child[index]) return false;
			p = p->child[index];
		}
		return p->is_word;
	}

	bool startsWith(string prefix) {
		TrieNode *p = root;
		for(auto i : prefix) {
			int index = i - 'a';
			if(!p->child[index]) return false;
			p = p->child[index];
		}
		return true;
	}
private:
	TrieNode *root;
};
