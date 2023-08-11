def apply(config, args):
    config["arch"] = "mipsel"
    config['baseimg'] = f'MAIN_T.EXE'
    config['myimg'] = f'build/MAIN_T.exe'
    config['mapfile'] = f'build/MAIN_T.map'
    config['source_directories'] = [f'src/game', 'include', f'asm/game']