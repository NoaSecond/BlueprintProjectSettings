# Blueprint Project Settings

Blueprint Project Settings is an Unreal Engine plugin that exposes information from `ProjectSettings` to Blueprints.

It lets you read project metadata such as the project name, version, description, publisher details without writing C++.

## Features

- Read project metadata directly from Blueprints
- Access grouped sections for About, Publisher, Legal, and Displayed information
- Use a full settings struct or read individual values from each section
- Runtime Blueprint function library

## Exposed Data

The plugin reads the following project settings fields:

- About: Project ID, Project Name, Project Version, Description, Project Thumbnail
- Publisher: Company Name, Company Distinguished Name, Homepage, Support Contact
- Legal: Copyright Notice, Licensing Terms
- Displayed: Project Displayed Title, Project Debug Title Info

## Requirements

- Unreal Engine with a compatible version for this plugin build
- Access to the project `Plugins` directory if you install the plugin locally

## Supported Platforms

- Windows (Win64)
- macOS
- Linux

## Installation

1. Copy the `BlueprintProjectSettings` plugin folder into your project’s `Plugins` directory.
   - Example: `YourProject/Plugins/BlueprintProjectSettings`
2. Open the project in Unreal Engine.
3. Enable the plugin from **Edit > Plugins** if needed.
4. Restart Unreal Engine if prompted.

## Usage

Once the plugin is enabled, search for the `Project Settings` Blueprint nodes.

Typical usage:

1. Call `Get Project Settings` to get the complete struct.
2. Break the struct to access the `About`, `Publisher`, `Legal`, or `Displayed` section.
3. Use the section helper nodes or the value getter nodes to read a specific field.

## Notes

- The plugin reads values from the default `GeneralProjectSettings` object.
- Empty fields in Project Settings will return empty values in Blueprint.
- The project thumbnail is returned as a soft object reference so it can be loaded on demand.

## Troubleshooting

### The plugin does not appear in the Plugins window

- Verify the plugin folder is inside the correct `Plugins` directory.
- Confirm the `.uplugin` file is present.
- Remove `Binaries` and `Intermediate` from the plugin folder if the plugin was copied from another machine or build.
- Regenerate project files and reopen the project.

### Unreal asks to rebuild

- Make sure the plugin build matches your Unreal Engine version.
- Rebuild the project from your IDE or from Unreal Engine.

### Blueprint nodes do not return values

- Check that the relevant fields are filled in **Edit > Project Settings > Project > Description**.
- Verify the plugin is enabled in the project.
- Review the Unreal output log for plugin or reflection errors.

## License

This plugin is distributed under the Fab Standard License.

## Support

For issues, feature requests, or support, open an issue in the repository or contact the author:

- Repository: https://github.com/NoaSecond/BlueprintProjectSettings
- Author: Noa Second - https://noasecond.com