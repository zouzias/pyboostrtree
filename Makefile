.PHONY: build

all: test

clean:
	-rm *.so boostrtrees.cpp
	-rm -rf build/ __pycache__/ *.egg-info/
	-rm -rf tests/__pycache__/
	-rm -rf dist/ build/

build:
	python setup.py build_ext --inplace

test: build
	py.test
