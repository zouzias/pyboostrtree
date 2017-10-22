
See https://www.codementor.io/arpitbhayani/host-your-python-package-using-github-on-pypi-du107t7ku


# Release to test PyPi

```
python setup.py sdist bdist_wheel upload -r pypitest
```


## Fetch package from pypitest

```
pip install --index-url https://test.pypi.org/simple/ boostrtrees
```
