#include <stdio.h>
#include <math.h>
#include <vector>
#include <fstream>

using namespace std;

double sphereVolume(double n, double r) {
    return pow(M_PI, n/2) * pow(r, n) / tgamma(n/2 + 1);
}

void sphereVolumes() {
    vector<double> x, y, z;

    auto canvas = new TCanvas("d", "c", 600, 600);
    auto graph2d = new TGraph2D();
    graph2d->SetTitle("Volumes of spheres with different dimensions and radii;Dimensions;Radius;Volume");
    // graph2d->GetXaxis()->CenterTitle();
    // graph2d->GetYaxis()->CenterTitle();
    // graph2d->GetZaxis()->CenterTitle();

    for (double n = 0.0; n <= 50.0; n++) {
        for (double r = 1.0; r <= 2.0; r += 0.05) {
            graph2d->AddPoint(n, r, sphereVolume(n, r));
        }
    }

    graph2d->Draw();

    canvas->Print("sphereVolumesRoot.svg");
}