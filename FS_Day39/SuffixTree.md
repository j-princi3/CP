```java

import java.util.*;

class SuffixTree {
    static final int NUM_CHARS = 26;

    static class SuffixTrieNode {
        SuffixTrieNode[] children = new SuffixTrieNode[NUM_CHARS];
        boolean isEndOfWord;

        SuffixTrieNode() {
            isEndOfWord = false;
            for (int i = 0; i < NUM_CHARS; i++)
                children[i] = null;
        }
    }

    static SuffixTrieNode root = new SuffixTrieNode();

    static void buildSuffixTrie(String text) {
        for (int i = 0; i < text.length(); i++) {
            insert(text.substring(i));
        }
    }

    static void insert(String word) {
        SuffixTrieNode node = root;
        for (char c : word.toCharArray()) {
            int index = c - 'a';

            if (node.children[index] == null) {
                node.children[index] = new SuffixTrieNode();
            }

            node = node.children[index];
        }

        node.isEndOfWord = true;
    }

    static void printAllSuffixes(SuffixTrieNode node, char[] buffer, int depth) {
        if (node == null) return;

        if (node.isEndOfWord) {
            System.out.println(new String(buffer, 0, depth));
        }

        for (int i = 0; i < NUM_CHARS; i++) {
            if (node.children[i] != null) {
                buffer[depth] = (char) (i + 'a');
                printAllSuffixes(node.children[i], buffer, depth + 1);
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();

        buildSuffixTrie(input);

        char[] buffer = new char[input.length()];
        printAllSuffixes(root, buffer, 0);
    }
}
```