public class World extends Cube {
    private static World _world = null;

    private World(double a) {
        super(a);
    }

    private World() {
        super();
    }

    public static World CreateWorld() {
        if (_world == null) _world = new World();

        return _world;
    }

    public static World CreateWorld(double a) {
        if (_world == null) _world = new World(a);

        return _world;
    }

}