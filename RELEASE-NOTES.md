
See https://www.codementor.io/arpitbhayani/host-your-python-package-using-github-on-pypi-du107t7ku


# Release to test PyPi

The following releases the Cython source code. To release a binary wheel use `bdist_wheel`.

```bash
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

```bash
pip install --index-url https://test.pypi.org/simple/ boostrtrees
```


## Signed package release

```bash
python setup.py sdist upload --sign
```

To verify,

```bash
gpg --verify dist/boostrtrees-0.0.1a3.tar.gz.asc dist/boostrtrees-0.0.1a3.tar.gz
```

### Signed package release of manylinux1

```bash
twine upload -r pypitest --sign dist/boostrtrees-*many*
```

Reference: 

* https://www.davidfischer.name/2012/05/signing-and-verifying-python-packages-with-pgp/
* https://hynek.me/articles/sharing-your-labor-of-love-pypi-quick-and-dirty/
