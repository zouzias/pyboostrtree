.PHONY: build

all: test

clean:
	-rm *.so boostrtrees.cpp
	-rm -rf build/ __pycache__/ *.egg-info/
	-rm -rf tests/__pycache__/
	-rm -rf dist/ build/

build:
	python setup.py build_ext --inplace

# Run tests
test: build
	py.test

# Run package benchmarks
benchmark: build
	cd benchmarks/ && python benchmark.py

docker: clean
	docker build docker-python/ -t boostrtrees
	docker run -t -v `pwd`:/opt/python-package/ boostrtrees make clean
	docker run -t -v `pwd`:/opt/python-package/ boostrtrees python3 setup.py sdist bdist_wheel
