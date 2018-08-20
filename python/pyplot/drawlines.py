from matplotlib import pyplot as plt


fig = plt.figure()

# l1 = plt.plot([0,0,7,7,0,5,7,0],[0,6,6,0,0,6,3,0], figure=fig, transform=fig.transFigure)
# l2 = plt.plot([0,7],[3,3], figure=fig, transform=fig.transFigure)
# l3 = plt.plot([5,5],[0,6], figure=fig, transform=fig.transFigure)
l1 = plt.plot([0,0,7,7,0,5,7,0],[0,6,6,0,0,6,3,0])
l2 = plt.plot([0,7],[3,3] )
l3 = plt.plot([5,5],[0,6] )

#fig.lines.extend([l1,l2,l3])

plt.show()


fig = plt.figure()
l1 = plt.plot([0,0,6,6,0,3,6,0],[0,7,7,0,0,7,5,0])
l2 = plt.plot([0,6],[5,5] )
l3 = plt.plot([3,3],[0,7] )

plt.show()

import numpy as np
import matplotlib.pyplot as plt
import matplotlib.lines as lines


fig = plt.figure()

l1 = lines.Line2D([0, 1], [0, 1], transform=fig.transFigure, figure=fig)

l2 = lines.Line2D([0, 1], [1, 0], transform=fig.transFigure, figure=fig)

fig.lines.extend([l1, l2])

plt.show()