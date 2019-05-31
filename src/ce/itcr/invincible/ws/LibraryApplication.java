package ce.itcr.invincible.ws;

import ce.itcr.invincible.ws.res.FoldersResource;

import javax.ws.rs.ApplicationPath;
import javax.ws.rs.core.Application;
import java.util.HashSet;
import java.util.Set;

@ApplicationPath("/")
public class LibraryApplication extends Application {

    public Set<Class<?>> getClasses() {
        Set<Class<?>> classes = new HashSet<>();
        classes.add(FoldersResource.class);
        return classes;
    }
}
