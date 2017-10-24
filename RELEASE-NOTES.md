
See https://www.codementor.io/arpitbhayani/host-your-python-package-using-github-on-pypi-du107t7ku


# Release to test PyPi

Releases source code for MacOS, use `bdist_wheel` to release wheels as well.

```
python setup.py sdist  upload -r pypitest
```


## Fetch package from pypitest

```
pip install --index-url https://test.pypi.org/simple/ boostrtrees
```
