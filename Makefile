.PHONY: clean All

All:
	@echo "----------Building project:[ trie - Debug ]----------"
	@cd "trie" && "$(MAKE)" -f  "trie.mk"
clean:
	@echo "----------Cleaning project:[ trie - Debug ]----------"
	@cd "trie" && "$(MAKE)" -f  "trie.mk" clean
