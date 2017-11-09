jupyter_skydata
===============================

A Custom Jupyter Widget Library

Installation
------------

To install use pip:

    $ pip install jupyter_skydata
    $ jupyter nbextension enable --py --sys-prefix jupyter_skydata


For a development installation (requires npm),

    $ git clone https://github.com/skydata/jupyter_skydata.git
    $ cd jupyter_skydata
    $ pip install -e .
    $ jupyter nbextension install --py --symlink --sys-prefix jupyter_skydata
    $ jupyter nbextension enable --py --sys-prefix jupyter_skydata
