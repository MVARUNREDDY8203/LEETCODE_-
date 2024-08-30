class TrieNode:
    def __init__(self):
        self.child = {}
        self.isWord = False

class Trie:

    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        p = self.root
        for char in word:
            if char not in p.child:
                p.child[char] = TrieNode()
            p = p.child[char]
        p.isWord = True

    def search(self, word: str) -> bool:
        p = self.root
        for char in word:
            if char not in p.child:
                return False
            p = p.child[char]
        return p.isWord

    def startsWith(self, prefix: str) -> bool:
        p = self.root
        for char in prefix:
            if char not in p.child:
                return False
            p = p.child[char]
        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)