{
  lib,
  callPackage,
  buildPythonPackage,
  fetchFromGitHub,
  # dependencies
  poetry-core,
  pcpp,
  pydantic,
  pydantic-settings,
  pyparsing,
  pyyaml,
}:

let
  platformdirs = callPackage ./platformdirs.nix { };
in

buildPythonPackage rec {
  pname = "keymap-drawer";
  version = "v0.15.0";
  format = "pyproject";

  src = fetchFromGitHub {
    owner = "caksoylar";
    repo = "keymap-drawer";
    rev = version;
    hash = "sha256-4bsAqhTYU0flQKm0ldN5V4cEdQ23oQnT+ZUeQKN1KsE=";
  };

  propagatedBuildInputs = [
    poetry-core
    pcpp
    platformdirs
    pydantic
    pydantic-settings
    pyparsing
    pyyaml
  ];

  meta = with lib; {
    description = "A module and CLI tool to help parse and draw keyboard layouts";
    mainProgram = "keymap";
    homepage = "https://keymap-drawer.streamlit.app/";
    license = licenses.mit;
  };
}
