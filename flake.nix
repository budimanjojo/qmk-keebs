{
  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
    flake-parts.url = "github:hercules-ci/flake-parts";
  };

  outputs =
    inputs:
    inputs.flake-parts.lib.mkFlake { inherit inputs; } {
      # supported system architectures should be added here
      systems = [ "x86_64-linux" ];
      perSystem =
        { pkgs, system, ... }:
        {
          devShells.default =
            with pkgs;
            mkShell {
              name = "qmk";
              packages = [
                (pkgs.callPackage ./nix/qmk.nix { })
                (pkgs.python3Packages.callPackage ./nix/keymap-drawer.nix { })
              ];
            };
        };
    };
}
