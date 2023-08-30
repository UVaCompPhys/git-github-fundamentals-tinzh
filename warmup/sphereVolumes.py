import math
import matplotlib
import matplotlib.pyplot as plt
import numpy as np

# use for gui
matplotlib.use("svg")

def sphereVolume(n, r):
    return pow(math.pi, n/2) * pow(r, n) / math.gamma(n/2 + 1)

def sphereVolumes():
    x = []
    y = []
    z = []

    for n in range(0, 50+1):
        for r in np.arange(1.0, 2.0+0.01, 0.05):
            x.append(n)
            y.append(r)
            z.append(sphereVolume(n, r));

    fig, ax = plt.subplots(subplot_kw={"projection": "3d"})
    ax.scatter(x, y, z)
    ax.set_xlabel("Dimensions")
    ax.set_ylabel("Radius")
    ax.set_zlabel("Volume")
    ax.set_title("Volumes of spheres with different dimensions and radii")

    plt.show()

    plt.savefig("sphereVolumesPython.svg")

sphereVolumes()