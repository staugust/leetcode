from ._version import version_info, __version__
from .example import *


def _jupyter_nbextension_paths():
    return [{
        'section': 'notebook',
        'src': 'static',
        'dest': 'jupyter_skydata',
        'require': 'jupyter_skydata/extension'
    }]


list = AugList
int = AugInt
AugList._ipython_display_ = ListDisplayWrapper()
AugInt._ipython_display_ = NumDisplayWrapper()