.PHONY: clean All

All:
	@echo "----------Building project:[ Section20_challenge4 - Debug ]----------"
	@cd "Section20_challenge4" && "$(MAKE)" -f  "Section20_challenge4.mk"
clean:
	@echo "----------Cleaning project:[ Section20_challenge4 - Debug ]----------"
	@cd "Section20_challenge4" && "$(MAKE)" -f  "Section20_challenge4.mk" clean
