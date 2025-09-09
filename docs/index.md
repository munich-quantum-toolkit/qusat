# MQT QuSAT - A Tool for Utilizing SAT in Quantum Computing

MQT QuSAT is a tool for utilizing satisfiablity testing (SAT) techniques in quantum computing.
It is developed as part of the _{doc}`Munich Quantum Toolkit (MQT) <mqt:index>`_.

We recommend you to start with the {doc}`installation instructions <installation>`.
Then proceed to read the quickstart section below.
If you are interested in the theory behind MQT QuSAT, have a look at the publications in the {doc}`publication list <references>`.

We appreciate any feedback and contributions to the project.
If you want to contribute, you can find more information in the {doc}`contribution guide <contributing>`.
If you are having trouble with the installation or the usage of MQT QuSAT, please let us know on our {doc}`support page <support>`.

## Quickstart

The results from {cite:p}`berent2022sat` can be reproduced by first building the project as described below and then executing the resulting `qusat_test` executable in the build directory.
In order to replicate the full range of results, the `test/test_satencoder.cpp` needs to be modified before building the project.
The corresponding lines to be changed are marked with a `// Paper Evaluation:` comment.

Running the executable, produces several `.json` files containing the experimental data. The python script `/results/visualizer.py` can be used
to plot the respective data.

Note that, as we use a randomized procedure to generate input data, the exact experimental data will slightly vary every time the benchmarks are run.
The experimental data used in the {cite:p}`berent2022sat` is available in `/results` directory.

```{toctree}
:hidden:

self
```

```{toctree}
:caption: User Guide
:glob:
:hidden:
:maxdepth: 1

installation
references
```

```{toctree}
:caption: Developers
:glob:
:hidden:
:maxdepth: 1

contributing
support
```

```{toctree}
:caption: Python API Reference
:glob:
:hidden:
:maxdepth: 6

api/mqt/qusat/index
```

## Contributors and Supporters

The _[Munich Quantum Toolkit (MQT)](https://mqt.readthedocs.io)_ is developed by the [Chair for Design Automation](https://www.cda.cit.tum.de/) at the [Technical University of Munich](https://www.tum.de/) and supported by the [Munich Quantum Software Company (MQSC)](https://munichquantum.software).
Among others, it is part of the [Munich Quantum Software Stack (MQSS)](https://www.munich-quantum-valley.de/research/research-areas/mqss) ecosystem, which is being developed as part of the [Munich Quantum Valley (MQV)](https://www.munich-quantum-valley.de) initiative.

<div style="margin-top: 0.5em">
<div class="only-light" align="center">
  <img src="https://raw.githubusercontent.com/munich-quantum-toolkit/.github/refs/heads/main/docs/_static/mqt-logo-banner-light.svg" width="90%" alt="MQT Banner">
</div>
<div class="only-dark" align="center">
  <img src="https://raw.githubusercontent.com/munich-quantum-toolkit/.github/refs/heads/main/docs/_static/mqt-logo-banner-dark.svg" width="90%" alt="MQT Banner">
</div>
</div>

Thank you to all the contributors who have helped make MQT QuSAT a reality!

<p align="center">
<a href="https://github.com/munich-quantum-toolkit/qusat/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=munich-quantum-toolkit/qusat" />
</a>
</p>

The MQT will remain free, open-source, and permissively licensed—now and in the future.
We are firmly committed to keeping it open and actively maintained for the quantum computing community.

To support this endeavor, please consider:

- Starring and sharing our repositories: [https://github.com/munich-quantum-toolkit](https://github.com/munich-quantum-toolkit)
- Contributing code, documentation, tests, or examples via issues and pull requests
- Citing the MQT in your publications (see {doc}`References <references>`)
- Using the MQT in research and teaching, and sharing feedback and use cases
- Sponsoring us on GitHub: [https://github.com/sponsors/munich-quantum-toolkit](https://github.com/sponsors/munich-quantum-toolkit)

<p align="center">
<iframe src="https://github.com/sponsors/munich-quantum-toolkit/button" title="Sponsor munich-quantum-toolkit" height="32" width="114" style="border: 0; border-radius: 6px;"></iframe>
</p>
