.PHONY: test
test:
	pio test -e d1_mini --verbose

.PHONY: publish
publish: test
	pio package publish
