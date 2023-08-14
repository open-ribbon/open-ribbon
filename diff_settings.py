def apply(config, args):
    config["arch"] = "mipsel"
    config['baseimg'] = f'iso/MAIN_T.EXE'
    config['myimg'] = f'build/MAIN_T.EXE'
    config['mapfile'] = f'build/vib-ribbon.map'
    config['source_directories'] = [f'src/game', 'include', f'asm/game']