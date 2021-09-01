# script for initalizing file content

Function FillContent {
    param([string]$Path, [Object]$Value);
    
    Set-Content -Path $Path -Value($Value);
}