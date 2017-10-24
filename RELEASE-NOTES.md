
See https://www.codementor.io/arpitbhayani/host-your-python-package-using-github-on-pypi-du107t7ku


# Release to test PyPi

Releases source code for MacOS, use `bdist_wheel` to release wheels as well.

```
python setup.py sdist  upload -r pypitest
```

For the upload, you need to set your credentials in `~/.pypirc`


```text
[distutils]
index-servers =
  pypi
  pypitest

[pypi]
repository: https://pypi.python.org/pypi
username: YOUR_USERNAME_HERE
password: YOUR_PASSWORD_HERE

[pypitest]
repository: https://test.pypi.org/legacy/
username: YOUR_USERNAME_HERE
password: YOUR_USERNAME_HERE
```

## Fetch package from pypitest

```
pip install --index-url https://test.pypi.org/simple/ boostrtrees
```
